package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"net/http"
	"os"
	"strings"
	"sync"
	"time"
        simplejson "github.com/bitly/go-simplejson"
)

func OneReq(url string, ch chan string, waitG *sync.WaitGroup) {
	resp, err := http.Head(url)
        astr := "{\"code\": 1}"
        json, _ := simplejson.NewJson([]byte(astr))
        fmt.Println(json)
	var s string
	if err == nil {
		s = fmt.Sprintf("%v\t%v", url, float64(resp.ContentLength)/1024/1024)
	} else {
		s = url + "\terror"
	}
	ch <- s
	waitG.Done()
}

func WriteOut(fout string, ch chan string, waitW *sync.WaitGroup) {
	of, err := os.OpenFile(fout, os.O_WRONLY|os.O_CREATE, 0666)
	if err != nil {
		panic(err)
	}
	defer of.Close()
	ow := bufio.NewWriter(of)
	for {
		s, open := <-ch
		if !open {
			break
		}
		ow.WriteString(s + "\n")
		ow.Flush()
	}
	waitW.Done()
}

func main() {
	fin := flag.String("i", "input.txt", "")
	fout := flag.String("o", "out.txt", "")
	cs := flag.Int("c", 100, "")
	flag.Parse()
	now := time.Now()
	ch := make(chan string, *cs)
	var waitG, waitW sync.WaitGroup
	file, err := os.Open(*fin)
	if err != nil {
		panic(err)
	}
	rd := bufio.NewReader(file)
	waitW.Add(1)
	go WriteOut(*fout, ch, &waitW)
	for {
		line, err := rd.ReadString('\n')
		if err != nil || io.EOF == err {
			break
		} else {
			waitG.Add(1)
			url := strings.Trim(line, "\n")
			go OneReq(url, ch, &waitG)
			time.Sleep(time.Duration(1) * time.Millisecond)
		}
	}
	waitG.Wait()
	close(ch)
	waitW.Wait()
	fmt.Printf("cost: %s\n", time.Since(now))
}

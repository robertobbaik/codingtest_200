# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

C++ 알고리즘 문제 풀이 저장소.

- **BOJ (백준)**: `{문제번호}.cpp` (예: `1000.cpp`, `10866.cpp`)
- **Programmers**: `pg-{문제번호}.cpp` (예: `pg-42584.cpp`)

## Build & Run

```bash
g++ -std=c++17 -O2 -o solution {파일명}.cpp && ./solution
```

## 파일 구조 컨벤션

**BOJ** — `main()` 사용, stdin/stdout:
```cpp
// BOJ #{번호} - {제목}
// https://www.acmicpc.net/problem/{번호}
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ...
    return 0;
}
```

**Programmers** — `solution()` 함수만 작성 (`main` 없음):
```cpp
// 프로그래머스 - {제목}
// https://school.programmers.co.kr/learn/courses/30/lessons/{번호}
#include <vector>
using namespace std;

{반환타입} solution({매개변수}) {
    // ...
}
```

## Learning Mode

이 저장소는 학습 목적으로 운영됩니다. Claude는 답을 직접 제공하지 않고 힌트와 질문으로 유도합니다.

- `functional` 문법 사용 자제
- 코드 평가는 스크립트 하단에 주석으로 남길 것 (`[코드 평가]`)
- 짚어볼 점은 스크립트 하단에 주석으로 남길 것 (`[짚어볼 점]`)
- 순서: `[코드 평가]` → `[짚어볼 점]`

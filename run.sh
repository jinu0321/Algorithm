#!/bin/bash

# 컴파일 옵션 설정
CXX="g++"
CXXFLAGS="-std=c++17 -O2 -Wall"
SOURCE="main.cpp"
EXECUTABLE="main"
INPUT="data.txt"

echo "=== 알고리즘 문제 풀이 환경 ==="

# main.cpp 파일 존재 확인
if [ ! -f "$SOURCE" ]; then
    echo "❌ 오류: $SOURCE 파일이 존재하지 않습니다."
    exit 1
fi

# data.txt 파일 존재 확인
if [ ! -f "$INPUT" ]; then
    echo "⚠️  경고: $INPUT 파일이 존재하지 않습니다."
    echo "빈 입력으로 실행합니다."
    touch "$INPUT"
fi

echo "📝 컴파일 중: $SOURCE"

# 컴파일 실행
if $CXX $CXXFLAGS -o $EXECUTABLE $SOURCE; then
    echo "✅ 컴파일 성공!"
    echo "🚀 실행 중..."
    echo "────────────────────────"
    
    # 실행 시간 측정
    start_time=$(date +%s.%N)
    
    # 프로그램 실행 (data.txt를 입력으로)
    ./$EXECUTABLE < $INPUT
    exit_code=$?
    
    end_time=$(date +%s.%N)
    execution_time=$(echo "$end_time - $start_time" | bc)
    
    echo "────────────────────────"
    echo "⏱️  실행 시간: ${execution_time}초"
    
    if [ $exit_code -eq 0 ]; then
        echo "✅ 프로그램이 정상적으로 종료되었습니다."
    else
        echo "❌ 프로그램이 오류 코드 $exit_code로 종료되었습니다."
    fi
    
    # 실행 파일 정리
    rm -f $EXECUTABLE
else
    echo "❌ 컴파일 실패!"
    exit 1
fi

# TimeCounter
## 概要
C で使用可能なプログラムの処理時間を計測し、結果を任意のファイルに保存することができるプログラム

## 使用方法
### C
``` C
//! 書き出すファイルパスを指定してインスタンス化
TimeCounter* counter = create_time_counter(path);
//! 計測開始
start_counter(counter);
//! 計測停止してファイルに書き出し
stop_counter(counter);
//! インスタンスの削除
delete_time_counter(counter);
```


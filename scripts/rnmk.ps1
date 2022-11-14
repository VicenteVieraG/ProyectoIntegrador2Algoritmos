g++ src/*.cpp main.cpp -o main
Get-ChildItem .\tests | ForEach-Object{
    Get-Content $_.FullName | .\main.exe 
}
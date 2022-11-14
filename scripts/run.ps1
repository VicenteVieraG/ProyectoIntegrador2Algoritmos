make
Get-ChildItem .\tests | ForEach-Object{
    Get-Content $_.FullName | .\main.exe 
}
make clean
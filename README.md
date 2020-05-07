## killprocess

Kill all processes by filename and class name.

Usage:

```bash
  -h [ --help ]             Display usage.
  -f [ --filename ] string  Filename to kill. e.g., "notepad.exe"
  -c [ --className ] string Process class name to kill. e.g., 
                            "ConsoleWindowClass"
```
  
Example:
```bash
killprocess.exe -c ConsoleWindowClass -f notepad.exe
```


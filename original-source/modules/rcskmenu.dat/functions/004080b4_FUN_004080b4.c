/*
 * FUN_004080b4 at 004080b4
 * undefined4 __register FUN_004080b4(undefined * param_1)
 * Address ranges: 004080b4-0040811b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004080b4(undefined *param_1)

{
  LPCSTR lpFileName;
  HANDLE hFindFile;
  BOOL BVar1;
  _WIN32_FIND_DATAA *lpFindFileData;
  _WIN32_FIND_DATAA local_150;
  _FILETIME local_10;
  undefined4 local_8;
  
  lpFindFileData = &local_150;
  lpFileName = FUN_00403f94(param_1);
  hFindFile = FindFirstFileA(lpFileName,lpFindFileData);
  if ((hFindFile != (HANDLE)0xffffffff) &&
     (FindClose(hFindFile), ((byte)local_150.dwFileAttributes & 0x10) == 0)) {
    FileTimeToLocalFileTime(&local_150.ftLastWriteTime,&local_10);
    BVar1 = FileTimeToDosDateTime(&local_10,(LPWORD)((int)&local_8 + 2),(LPWORD)&local_8);
    if (BVar1 != 0) {
      return local_8;
    }
  }
  return 0xffffffff;
}


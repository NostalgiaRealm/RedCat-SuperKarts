/*
 * FUN_0044c780 at 0044c780
 * undefined __register FUN_0044c780(void)
 * Address ranges: 0044c780-0044c7e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044c780(void)

{
  byte *lpString;
  undefined4 uVar1;
  byte local_30 [32];
  undefined4 local_10;
  undefined1 local_c;
  DWORD local_8;
  undefined1 local_4;
  
  _DAT_0047d824 = RegisterWindowMessageA("commdlg_help");
  _DAT_0047d828 = RegisterWindowMessageA("commdlg_FindReplace");
  uVar1 = 1;
  local_10 = DAT_0047d4dc;
  local_c = 0;
  local_8 = GetCurrentThreadId();
  local_4 = 0;
  lpString = FUN_004089f4(local_30,(byte *)"WndProcPtr%.8X%.8X",&local_10,uVar1);
  DAT_0047ba38 = GlobalAddAtomA((LPCSTR)lpString);
  return;
}


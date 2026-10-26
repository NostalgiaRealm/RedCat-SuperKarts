/*
 * FUN_004210c2 at 004210c2
 * undefined __stdcall FUN_004210c2(void)
 * Address ranges: 004210c2-0042115a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004210c2(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_0043f928 == 0) {
    FUN_00424bb9();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_0043e334,0x104);
  _DAT_0043e2f8 = &DAT_0043e334;
  pbVar2 = &DAT_0043e334;
  if (*DAT_0043f934 != 0) {
    pbVar2 = DAT_0043f934;
  }
  FUN_0042115b(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_0042115b(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_0043e2e0 = puVar1;
  _DAT_0043e2dc = local_8 + -1;
  return;
}


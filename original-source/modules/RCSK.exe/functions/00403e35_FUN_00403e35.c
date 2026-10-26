/*
 * FUN_00403e35 at 00403e35
 * undefined __stdcall FUN_00403e35(void)
 * Address ranges: 00403e35-00403ecd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403e35(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_0040a12c == 0) {
    FUN_00405209();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_00408c68,0x104);
  _DAT_00408c3c = &DAT_00408c68;
  pbVar2 = &DAT_00408c68;
  if (*DAT_0040a124 != 0) {
    pbVar2 = DAT_0040a124;
  }
  FUN_00403ece(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_00403ece(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_00408c24 = puVar1;
  _DAT_00408c20 = local_8 + -1;
  return;
}


/*
 * FUN_00415714 at 00415714
 * undefined FUN_00415714(void)
 * Address ranges: 00415714-004157bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415714(void)

{
  LPVOID pvVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004157c0;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  _DAT_0047d620 = _DAT_0047d620 + 1;
  if (_DAT_0047d620 == 0) {
    FUN_0040ef64(DAT_0047d4dc);
    FUN_0040bf7c((int)DAT_0047d618);
    FUN_004156a0();
    FUN_00402eac(DAT_0047d624);
    FUN_00402eac(DAT_0047d628);
    FUN_00412378(0,(char *)0x0);
    FUN_00402eac(DAT_0047d630);
    DAT_0047d630 = (int *)0x0;
    pvVar1 = FUN_00406144();
    FUN_00402eac(*(int **)((int)pvVar1 + 0xc));
    FUN_0041475c();
    FUN_00402eac(DAT_0047d618);
    DAT_0047d618 = (int *)0x0;
    FUN_004052d4(0x41570c);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0047d634);
  }
  *in_FS_OFFSET = uStack_10;
  return;
}


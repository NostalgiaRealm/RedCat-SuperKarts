/*
 * FUN_00403500 at 00403500
 * undefined __stdcall FUN_00403500(void)
 * Address ranges: 00403500-004035c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403500(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_0043845c != 0) {
    local_14 = 0;
    local_c = DAT_0042c350;
    local_10 = 0;
    local_8 = DAT_0042c354;
    local_24 = 0;
    local_1c = DAT_0042c350;
    local_20 = 0;
    local_18 = DAT_0042c354;
    FUN_004028c2(DAT_00438438);
    FUN_004028c2(DAT_00438418);
    iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                      (DAT_00438438,&local_14,DAT_00438418,&local_24,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___0042d654);
    }
  }
  return;
}


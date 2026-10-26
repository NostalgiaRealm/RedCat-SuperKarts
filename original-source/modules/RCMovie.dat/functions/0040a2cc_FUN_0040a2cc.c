/*
 * FUN_0040a2cc at 0040a2cc
 * undefined4 __cdecl FUN_0040a2cc(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 0040a2cc-0040a407
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040a2cc(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_28 = 0;
  local_24 = 0;
  local_1c = *(undefined4 *)(DAT_0043d510 + 8);
  local_20 = *(undefined4 *)(DAT_0043d510 + 4);
  local_18 = 0;
  local_14 = 0;
  local_c = *(undefined4 *)(DAT_0043d510 + 8);
  local_10 = *(undefined4 *)(DAT_0043d510 + 4);
  while (DAT_0043d51c != 0) {
    if (*(int *)(DAT_0043d510 + 0x68) != 0) {
      FUN_0040a18a(param_3);
    }
    local_8 = FUN_0040235c(DAT_00438418);
    _SmackToBuffer_28(DAT_0043d510,0,0,DAT_0042c350,DAT_0042c354,local_8,0);
    _SmackDoFrame_4(DAT_0043d510);
    FUN_004027f9(DAT_00438418,local_8);
    FUN_004028c2(DAT_00438434);
    iVar1 = (**(code **)(*DAT_00438434 + 0x14))
                      (DAT_00438434,&local_18,DAT_00438418,&local_28,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___00431488);
    }
    FUN_0040a24e();
  }
  return 0;
}


/*
 * FUN_0040a408 at 0040a408
 * undefined4 __cdecl FUN_0040a408(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5)
 * Address ranges: 0040a408-0040a565
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_0040a408(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

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
  
  DAT_0043d520 = 0;
  local_28 = 0;
  local_24 = 0;
  local_1c = *(undefined4 *)(DAT_0043d510 + 8);
  local_20 = *(undefined4 *)(DAT_0043d510 + 4);
  local_14 = param_1;
  local_10 = param_2;
  local_8 = param_4;
  local_c = param_3;
  while (DAT_0043d51c != 0) {
    if (*(int *)(DAT_0043d510 + 0x68) != 0) {
      FUN_0040a18a(param_5);
    }
    local_18 = FUN_0040235c(DAT_00438418);
    _SmackToBuffer_28(DAT_0043d510,0,0,DAT_0042c350,DAT_0042c354,local_18,0);
    _SmackDoFrame_4(DAT_0043d510);
    FUN_004027f9(DAT_00438418,local_18);
    FUN_004028c2(DAT_00438438);
    iVar1 = (**(code **)(*DAT_00438438 + 0x14))
                      (DAT_00438438,&local_14,DAT_00438418,&local_28,0x1000000,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____blitting_error___s___004314b4);
    }
    FUN_0040a24e();
    FUN_00401cf3();
    DAT_0043d520 = DAT_0043d520 + 1;
  }
  if ((DAT_0043d520 & 1) != 0) {
    FUN_00401cf3();
  }
  return 0;
}


/*
 * FUN_0043d130 at 0043d130
 * undefined FUN_0043d130(void)
 * Address ranges: 0043d130-0043d20c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043d130(int param_1,undefined4 param_2)

{
  int *piVar1;
  int local_34 [2];
  undefined1 local_2c [12];
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  FUN_0043d300(param_2,&local_10);
  FUN_0043d6f0(local_c,&local_1c);
  if (local_8 != 0.0) {
    FUN_0043d710();
    local_34[0] = param_1;
    local_34[1] = 0;
    piVar1 = (int *)FUN_0043d840(local_2c,local_34);
    local_20 = piVar1[1];
    *(float *)(*piVar1 + 0x10) = local_8;
  }
  *(undefined4 *)(param_1 * 0xd0 + 0x94 + DAT_0067ee20) = local_4;
  FUN_0048fda0(param_1,local_1c,local_18,local_14,0,local_10,0x3dcccccd,0x40800000,0x3f800000);
  *(undefined4 *)(param_1 * 0xd0 + 0x94 + DAT_0067ee20) = local_4;
  FUN_004939d0(param_1);
  return;
}


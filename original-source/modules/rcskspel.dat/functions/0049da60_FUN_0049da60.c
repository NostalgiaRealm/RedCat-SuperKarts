/*
 * FUN_0049da60 at 0049da60
 * undefined FUN_0049da60(void)
 * Address ranges: 0049da60-0049dbf6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_0049da60(int param_1,float param_2,float param_3,float param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  FUN_0049d9e0(&local_24,local_c,&local_18);
  param_2 = param_2 - local_24;
  param_3 = param_3 - local_20;
  param_4 = param_4 - local_1c;
  fVar1 = SQRT(param_2 * param_2 + param_3 * param_3 + param_4 * param_4);
  if (fVar1 < (float)*(int *)(param_1 + 0xc)) {
    if (fVar1 == 0.0) {
      local_30 = 0.0;
      local_2c = 1.0;
      local_28 = 0.0;
    }
    else {
      local_30 = param_2 / fVar1;
      local_2c = param_3 / fVar1;
      local_28 = param_4 / fVar1;
    }
    iVar2 = FUN_0049d870();
    if (iVar2 == 0) {
      FUN_0049d780(param_8);
    }
    uVar3 = FUN_0049d980(fVar1);
    *(undefined4 *)(param_1 + 0x48) = uVar3;
    FUN_0049d570();
    uVar3 = FUN_0049d900(&local_30,local_c);
    FUN_0049d650(uVar3);
    uVar3 = FUN_0049d8a0(local_18,local_14,local_10,param_5,param_6,param_7,local_30,local_2c,
                         local_28);
    FUN_0049d5e0(uVar3);
  }
  else {
    iVar2 = FUN_0049d870();
    if (iVar2 != 0) {
      FUN_0049d7a0();
      return;
    }
  }
  return;
}


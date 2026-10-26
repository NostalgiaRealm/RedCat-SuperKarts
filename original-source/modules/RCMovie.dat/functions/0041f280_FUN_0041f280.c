/*
 * FUN_0041f280 at 0041f280
 * undefined __fastcall FUN_0041f280(int param_1)
 * Address ranges: 0041f280-0041f2df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0041f280(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))();
  }
  if (*(int *)(param_1 + 0x2c) == 1) {
    FUN_00401cf3();
  }
  else if (*(int *)(param_1 + 0x2c) == 2) {
    uVar6 = 0;
    iVar1 = *DAT_00438434;
    uVar5 = 0x1000000;
    uVar2 = FUN_0041e8d0(param_1 + 0x18);
    uVar3 = FUN_0041e8d0(uVar2);
    uVar2 = DAT_00438418;
    uVar4 = FUN_0041e8d0(param_1 + 0x18);
    uVar4 = FUN_0041e8d0(uVar4);
    (**(code **)(iVar1 + 0x14))(DAT_00438434,uVar4,uVar2,uVar3,uVar5,uVar6);
    return;
  }
  return;
}


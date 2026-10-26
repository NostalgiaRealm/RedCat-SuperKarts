/*
 * FUN_00419fb4 at 00419fb4
 * undefined __register FUN_00419fb4(int * param_1, int * param_2)
 * Address ranges: 00419fb4-00419fef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419fb4(int *param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar3 = *(undefined4 *)(*param_1 + 0x30);
  uVar2 = *(undefined4 *)(*param_1 + 0x44);
  piVar4 = param_1;
  uVar1 = FUN_00419f5c();
  (**(code **)(*param_2 + 8))(param_2,&DAT_00419ff8,uVar1,uVar2,param_1,uVar3,piVar4);
  return;
}


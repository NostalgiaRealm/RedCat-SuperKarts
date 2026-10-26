/*
 * FUN_0045354c at 0045354c
 * undefined __register FUN_0045354c(int param_1, uint param_2, undefined4 * param_3)
 * Address ranges: 0045354c-00453593
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045354c(int param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  piVar1 = (int *)FUN_00453594(param_1,param_2);
  uVar2 = (**(code **)(*piVar1 + 0x20))();
  puVar4 = param_3;
  piVar1 = (int *)FUN_00453594(param_1,param_2);
  uVar3 = (**(code **)(*piVar1 + 0x2c))();
  FUN_0040ebe8(0,0,uVar3,puVar4,uVar2);
  if (*(short *)(param_1 + 0x62) != 0) {
    (**(code **)(param_1 + 0x60))(*(undefined4 *)(param_1 + 100),param_1,param_2,param_3);
  }
  return;
}


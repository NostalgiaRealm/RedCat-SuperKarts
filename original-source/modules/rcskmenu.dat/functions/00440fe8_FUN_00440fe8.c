/*
 * FUN_00440fe8 at 00440fe8
 * int * __register FUN_00440fe8(int * param_1, undefined4 * param_2)
 * Address ranges: 00440fe8-0044106d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00440fe8(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_1c [4];
  
  piVar3 = local_1c;
  for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = *param_2;
    param_2 = param_2 + 1;
    piVar3 = piVar3 + 1;
  }
  piVar3 = (int *)0x0;
  iVar2 = (**(code **)(*param_1 + 0x54))();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*param_1 + 0x54))();
    iVar1 = FUN_00402df4(param_1);
    if (iVar2 != iVar1) {
      iVar2 = (**(code **)(*param_1 + 0x54))();
      piVar3 = (int *)(**(code **)(iVar2 + 0x2c))(iVar2,1,*(undefined4 *)PTR_DAT_0047c86c);
      FUN_0043ee8c(piVar3,local_1c[1]);
      FUN_0043ee6c(piVar3,local_1c[0]);
      FUN_0043f0c8(piVar3,local_1c[2] - local_1c[0]);
      FUN_0043f10c(piVar3,local_1c[3] - local_1c[1]);
    }
  }
  return piVar3;
}


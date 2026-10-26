/*
 * FUN_004149d0 at 004149d0
 * undefined __register FUN_004149d0(int * param_1)
 * Address ranges: 004149d0-00414a23
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004149d0(int *param_1)

{
  int *piVar1;
  
  while ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    piVar1 = (int *)FUN_0040f798((undefined4 *)param_1[4]);
    if (((*(byte *)((int)piVar1 + 0x21) & 1) == 0) && ((*(ushort *)(param_1 + 8) & 0x210) != 0x210))
    {
      FUN_00414918((int)param_1,(int)piVar1);
    }
    else {
      FUN_00414998(param_1,(int)piVar1);
    }
    (**(code **)(*piVar1 + -4))(piVar1,1);
  }
  return;
}


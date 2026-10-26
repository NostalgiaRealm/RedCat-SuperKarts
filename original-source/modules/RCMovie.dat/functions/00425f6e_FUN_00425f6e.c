/*
 * FUN_00425f6e at 00425f6e
 * int __stdcall FUN_00425f6e(int * param_1)
 * Address ranges: 00425f6e-00425fb3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00425f6e(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_0042405c();
    return iVar3;
  }
  if ((DAT_0043e570 != (FARPROC)0x0) &&
     (bVar2 = FUN_0042600a(DAT_0043e570), CONCAT31(extraout_var,bVar2) != 0)) {
    iVar3 = (*DAT_0043e570)(param_1);
    return iVar3;
  }
  return 0;
}


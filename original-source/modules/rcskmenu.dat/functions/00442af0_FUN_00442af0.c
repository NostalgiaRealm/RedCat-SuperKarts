/*
 * FUN_00442af0 at 00442af0
 * undefined __register FUN_00442af0(int * param_1)
 * Address ranges: 00442af0-00442b43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442af0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0043f5c0((int)param_1);
  if (iVar1 < 1) {
    iVar1 = FUN_00408548("");
    param_1[0x15] = iVar1;
  }
  else {
    piVar2 = FUN_00408528(iVar1 + 1);
    param_1[0x15] = (int)piVar2;
    iVar1 = FUN_0040853c((int)piVar2);
    FUN_0043f5d0((int)param_1,piVar2,iVar1);
  }
  FUN_0043e22c();
  (**(code **)(*param_1 + 0x9c))();
  return;
}


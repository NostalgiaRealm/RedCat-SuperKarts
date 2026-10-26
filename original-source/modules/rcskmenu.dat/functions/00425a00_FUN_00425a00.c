/*
 * FUN_00425a00 at 00425a00
 * undefined __register FUN_00425a00(int * param_1, int param_2)
 * Address ranges: 00425a00-00425a50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00425a00(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  uVar2 = FUN_00403024(piVar1,(int)&PTR_FUN_00421f80);
  if ((char)uVar2 == '\0') {
    *(char *)((int)param_1 + 0x1fa) = (char)param_1[0x7e];
  }
  else {
    *(bool *)((int)param_1 + 0x1fa) = param_1 == piVar1;
  }
  (**(code **)(*param_1 + 0xbc))(param_1,*(undefined1 *)((int)param_1 + 0x1fa));
  FUN_00444c54((int)param_1,param_2);
  return;
}


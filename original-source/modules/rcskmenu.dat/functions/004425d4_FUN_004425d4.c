/*
 * FUN_004425d4 at 004425d4
 * undefined __register FUN_004425d4(int * param_1, int * param_2)
 * Address ranges: 004425d4-0044264e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004425d4(int *param_1,int *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  
  FUN_004405f0((int)param_1,0xb036,param_2,0);
  uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_0043be00);
  if ((char)uVar2 == '\0') {
    bVar1 = FUN_00445a20((int)param_1);
    if (bVar1) {
      FUN_0043fa78((int)param_2,*(char *)((int)param_2 + 0x47),'\0');
    }
  }
  else {
    FUN_0044244c(param_2,'\x01');
    FUN_00442c8c(param_2);
  }
  FUN_004424b8((int)param_1,param_2);
  FUN_004405f0((int)param_1,0xb02c,param_2,0);
  FUN_0044221c(param_1);
  return;
}


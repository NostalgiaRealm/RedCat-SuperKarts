/*
 * FUN_004383fc at 004383fc
 * undefined FUN_004383fc(void)
 * Address ranges: 004383fc-00438434
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004383fc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1;
  if ((*(int *)(param_1 + 0x58) == 0) &&
     (uVar1 = FUN_00403024(*(int **)(param_1 + 4),(int)&PTR_FUN_00435170), (char)uVar1 != '\0')) {
    iVar2 = 0;
  }
  if (*(short *)(param_1 + 0x7a) != 0) {
    (**(code **)(param_1 + 0x78))(*(undefined4 *)(param_1 + 0x7c),param_1,iVar2,param_2);
  }
  return;
}


/*
 * FUN_0046cb5c at 0046cb5c
 * undefined FUN_0046cb5c(void)
 * Address ranges: 0046cb5c-0046cbcf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046cb5c(int *param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  
  piVar1 = (int *)param_1[0x7c];
  FUN_00417fbc((int *)piVar1[5],'\x01');
  FUN_00417bbc((int *)piVar1[4],0x80000006);
  FUN_00417cc8((int *)piVar1[4],1);
  FUN_00418674(piVar1,0,0,param_1[0xf],param_1[0xe]);
  iVar3 = 0;
  bVar2 = 0;
  do {
    if ((char)param_1[(uint)bVar2 * 4 + 0x7e] != '\0') {
      FUN_0046c860(param_1,bVar2,iVar3);
      iVar3 = iVar3 + param_1[0xa9] + -1;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 != 9);
  return;
}


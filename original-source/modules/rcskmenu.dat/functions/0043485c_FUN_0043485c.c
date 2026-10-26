/*
 * FUN_0043485c at 0043485c
 * undefined FUN_0043485c(void)
 * Address ranges: 0043485c-004348e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043485c(int *param_1,int *param_2)

{
  char cVar1;
  int iStack_1c;
  int iStack_18;
  char cStack_14;
  undefined4 uStack_10;
  
  FUN_00433a14(param_1);
  uStack_10 = FUN_00411894(param_2);
  (**(code **)(*param_2 + 4))(param_2,&iStack_1c,4);
  (**(code **)(*param_2 + 4))(param_2,&iStack_18,4);
  cVar1 = (char)iStack_1c;
  cStack_14 = (char)((uint)iStack_1c >> 8);
  FUN_004118a4(param_2,uStack_10);
  if (((iStack_1c == iStack_18) || (cVar1 != 'I')) || (cStack_14 != 'L')) {
    FUN_00434548(param_1,param_2);
  }
  else {
    FUN_004347d8(param_1,(int)param_2);
  }
  return;
}


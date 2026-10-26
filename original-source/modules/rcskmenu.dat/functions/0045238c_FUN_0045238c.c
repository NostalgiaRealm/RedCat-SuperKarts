/*
 * FUN_0045238c at 0045238c
 * undefined __register FUN_0045238c(int * param_1, int * param_2)
 * Address ranges: 0045238c-004523f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045238c(int *param_1,int *param_2)

{
  char cVar1;
  undefined2 uStack_1c;
  int iStack_1a;
  undefined2 uStack_16;
  undefined2 uStack_14;
  int iStack_12;
  
  cVar1 = (**(code **)(*param_1 + 0x1c))();
  if (cVar1 == '\0') {
    uStack_1c = 0x4d42;
    iStack_12 = FUN_00451e38((int)param_1);
    iStack_12 = iStack_12 + 0xe;
    iStack_1a = *(int *)(*(int *)(param_1[9] + 0xc) + 0x14) + iStack_12;
    uStack_16 = 0;
    uStack_14 = 0;
    FUN_00411920(param_2,&uStack_1c,0xe);
    (**(code **)(*param_1 + 0x44))(param_1,param_2);
  }
  return;
}


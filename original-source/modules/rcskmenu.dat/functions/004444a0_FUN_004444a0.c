/*
 * FUN_004444a0 at 004444a0
 * undefined1 __register FUN_004444a0(int * param_1, int param_2)
 * Address ranges: 004444a0-00444505
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_004444a0(int *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  undefined3 extraout_var;
  
  piVar3 = FUN_004298bc(param_1);
  if ((((piVar3 != (int *)0x0) && (param_1 != piVar3)) && (*(char *)((int)piVar3 + 0x215) != '\0'))
     && (cVar1 = FUN_004444a0(piVar3,param_2), cVar1 != '\0')) {
    return 1;
  }
  bVar2 = FUN_004297c4(*(uint *)(param_2 + 8));
  if (((*(byte *)((int)param_1 + 0x41) & 0x10) == 0) &&
     (FUN_00403088(param_1,param_2 + 4,CONCAT31(extraout_var,bVar2)), *(short *)(param_2 + 4) == 0))
  {
    return 1;
  }
  return 0;
}


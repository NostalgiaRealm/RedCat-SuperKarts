/*
 * FUN_004c7efa at 004c7efa
 * undefined FUN_004c7efa(void)
 * Address ranges: 004c7efa-004c7f91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_004c7efa(undefined4 param_1,undefined4 param_2,undefined8 param_3,double param_4,
                    undefined4 param_5)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_004c8245(param_1,&param_4,param_5);
  if (iVar1 == 0) {
    FUN_004c7f92();
  }
  iVar1 = FUN_004c852f(param_1);
  if ((DAT_005037cc == 0) && (iVar1 != 0)) {
    fVar2 = (float10)FUN_004c845c(iVar1,param_2,param_3,0,param_4,param_5);
    return fVar2;
  }
  FUN_004c84e4(iVar1);
  FUN_004c86cf();
  return (float10)param_4;
}


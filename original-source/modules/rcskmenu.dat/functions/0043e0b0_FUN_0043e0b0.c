/*
 * FUN_0043e0b0 at 0043e0b0
 * int * __register FUN_0043e0b0(POINT * param_1, undefined4 param_2)
 * Address ranges: 0043e0b0-0043e0f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0043e0b0(POINT *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int local_18 [2];
  
  piVar1 = FUN_0043e07c(param_1);
  piVar3 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    cVar4 = '\0';
    FUN_0043f1f0(piVar1,&param_1->x,local_18);
    piVar2 = (int *)FUN_00442f94((int)piVar1,local_18,param_2,cVar4);
    piVar3 = piVar1;
    if (piVar2 != (int *)0x0) {
      piVar3 = piVar2;
    }
  }
  return piVar3;
}


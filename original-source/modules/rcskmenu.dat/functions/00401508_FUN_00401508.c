/*
 * FUN_00401508 at 00401508
 * undefined4 __register FUN_00401508(int * param_1, uint * param_2)
 * Address ranges: 00401508-00401596
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401508(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int local_18;
  int local_14;
  
  piVar3 = param_1;
  while( true ) {
    uVar1 = *param_2;
    uVar2 = piVar3[2];
    if ((uVar2 <= uVar1) && (uVar1 + param_2[1] <= uVar2 + piVar3[3])) break;
    piVar3 = (int *)*piVar3;
    if (param_1 == piVar3) {
      return 0;
    }
  }
  if (uVar1 == uVar2) {
    piVar3[2] = piVar3[2] + param_2[1];
    uVar2 = param_2[1];
    piVar3[3] = piVar3[3] - uVar2;
    if (piVar3[3] == 0) {
      uVar2 = FUN_0040147c(piVar3);
    }
  }
  else if (*param_2 + param_2[1] == uVar2 + piVar3[3]) {
    piVar3[3] = piVar3[3] - param_2[1];
  }
  else {
    local_18 = *param_2 + param_2[1];
    local_14 = (uVar2 + piVar3[3]) - local_18;
    piVar3[3] = *param_2 - uVar2;
    uVar2 = FUN_0040144c(piVar3,&local_18);
    if ((char)uVar2 == '\0') {
      return 0;
    }
  }
  return CONCAT31((int3)(uVar2 >> 8),1);
}


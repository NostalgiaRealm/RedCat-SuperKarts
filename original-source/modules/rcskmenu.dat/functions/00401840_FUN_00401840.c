/*
 * FUN_00401840 at 00401840
 * undefined __register FUN_00401840(int param_1, int * param_2)
 * Address ranges: 00401840-004018cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401840(int param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int local_18 [2];
  
  uVar2 = param_1 + 0x3fffU & 0xffffc000;
  piVar1 = DAT_0047d468;
  do {
    for (; (int **)piVar1 != &DAT_0047d468; piVar1 = (int *)*piVar1) {
      if ((int)uVar2 <= piVar1[3]) {
        FUN_0040172c(piVar1[2],uVar2,param_2);
        if (*param_2 == 0) {
          return;
        }
        piVar1[2] = piVar1[2] + param_2[1];
        piVar1[3] = piVar1[3] - param_2[1];
        if (piVar1[3] != 0) {
          return;
        }
        FUN_0040147c(piVar1);
        return;
      }
    }
    FUN_00401598(uVar2,param_2);
    if (*param_2 == 0) {
      return;
    }
    FUN_00401494((int *)&DAT_0047d468,param_2,local_18);
    piVar1 = DAT_0047d468;
  } while (local_18[0] != 0);
  FUN_00401674((LPVOID)*param_2,param_2[1],local_18);
  *param_2 = 0;
  return;
}


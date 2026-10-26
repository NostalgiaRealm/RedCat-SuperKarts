/*
 * FUN_004018d0 at 004018d0
 * undefined __register FUN_004018d0(LPVOID param_1, int param_2, int * param_3)
 * Address ranges: 004018d0-004019f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004018d0(LPVOID param_1,int param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  LPVOID local_20;
  int local_1c;
  int local_18 [2];
  
  uVar2 = param_2 + 0x3fffU & 0xffffc000;
  piVar1 = DAT_0047d468;
LAB_004018f6:
  do {
    for (; ((int **)piVar1 != &DAT_0047d468 && (param_1 != (LPVOID)piVar1[2]));
        piVar1 = (int *)*piVar1) {
    }
    if (param_1 == (LPVOID)piVar1[2]) {
      if ((int)uVar2 <= piVar1[3]) goto LAB_004019a3;
      FUN_004015fc((LPVOID)(piVar1[2] + piVar1[3]),uVar2 - piVar1[3],(int *)&local_20);
      if (local_20 != (LPVOID)0x0) {
        FUN_00401494((int *)&DAT_0047d468,(int *)&local_20,local_18);
        piVar1 = DAT_0047d468;
        if (local_18[0] == 0) {
          FUN_00401674(local_20,local_1c,local_18);
          *param_3 = 0;
          return;
        }
        goto LAB_004018f6;
      }
    }
    FUN_004015fc(param_1,uVar2,(int *)&local_20);
    if (local_20 == (LPVOID)0x0) {
LAB_004019a3:
      if ((param_1 != (LPVOID)piVar1[2]) || (piVar1[3] < (int)uVar2)) {
        *param_3 = 0;
        return;
      }
      FUN_0040172c((uint)piVar1[2],uVar2,param_3);
      if (*param_3 == 0) {
        return;
      }
      piVar1[2] = piVar1[2] + param_3[1];
      piVar1[3] = piVar1[3] - param_3[1];
      if (piVar1[3] != 0) {
        return;
      }
      FUN_0040147c(piVar1);
      return;
    }
    FUN_00401494((int *)&DAT_0047d468,(int *)&local_20,local_18);
    piVar1 = DAT_0047d468;
    if (local_18[0] == 0) {
      FUN_00401674(local_20,local_1c,local_18);
      *param_3 = 0;
      return;
    }
  } while( true );
}


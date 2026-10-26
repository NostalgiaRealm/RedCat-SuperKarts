/*
 * FUN_0040b794 at 0040b794
 * int __register FUN_0040b794(undefined * param_1, int * param_2)
 * Address ranges: 0040b794-0040b81f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040b794(undefined *param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_0047d5b8 == '\0') {
    iVar4 = FUN_00407d7c(param_1,param_2);
  }
  else {
    uVar3 = FUN_00403dd0((int)param_1);
    iVar4 = FUN_00404104(param_2,uVar3);
    iVar5 = 1;
    if (0 < (int)uVar3) {
      do {
        iVar4 = FUN_00403fa0(param_2);
        *(undefined *)(iVar4 + -1 + iVar5) = param_1[iVar5 + -1];
        if (((byte)(&DAT_0047b114)[(int)(uint)(byte)param_1[iVar5 + -1] >> 3] >>
             ((byte)param_1[iVar5 + -1] & 7) & 1) == 0) {
          cVar2 = *(char *)(*param_2 + -1 + iVar5);
          iVar4 = CONCAT31((int3)((uint)*param_2 >> 8),cVar2 + -0x5b);
          if ((byte)(cVar2 + 0xbfU) < 0x1a) {
            iVar4 = FUN_00403fa0(param_2);
            pcVar1 = (char *)(iVar4 + -1 + iVar5);
            *pcVar1 = *pcVar1 + ' ';
          }
        }
        else {
          iVar4 = FUN_00403fa0(param_2);
          *(undefined *)(iVar4 + -1 + iVar5 + 1) = param_1[iVar5];
          iVar5 = iVar5 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 <= (int)uVar3);
    }
  }
  return iVar4;
}


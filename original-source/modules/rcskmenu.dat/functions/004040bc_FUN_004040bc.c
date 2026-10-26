/*
 * FUN_004040bc at 004040bc
 * int __register FUN_004040bc(char * param_1, char * param_2)
 * Address ranges: 004040bc-00404100
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004040bc(char *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  if (param_1 != (char *)0x0) {
    if (param_2 == (char *)0x0) {
      return 0;
    }
    iVar4 = *(int *)(param_1 + -4) + -1;
    if (-1 < iVar4) {
      iVar2 = *(int *)(param_2 + -4) - iVar4;
      bVar7 = iVar2 == 0;
      pcVar5 = param_2;
      if (!bVar7 && iVar4 <= *(int *)(param_2 + -4)) {
LAB_004040dc:
        do {
          if (iVar2 != 0) {
            iVar2 = iVar2 + -1;
            pcVar1 = pcVar5 + 1;
            bVar7 = *param_1 == *pcVar5;
            pcVar5 = pcVar1;
            if (!bVar7) goto LAB_004040dc;
          }
          iVar3 = iVar4;
          pcVar6 = pcVar5;
          pcVar1 = param_1;
          if (!bVar7) {
            return 0;
          }
          do {
            if (iVar3 == 0) break;
            bVar7 = pcVar1[1] == *pcVar6;
            iVar3 = iVar3 + -1;
            pcVar6 = pcVar6 + 1;
            pcVar1 = pcVar1 + 1;
          } while (bVar7);
          if (bVar7) {
            return (int)pcVar5 - (int)param_2;
          }
        } while( true );
      }
    }
  }
  return 0;
}


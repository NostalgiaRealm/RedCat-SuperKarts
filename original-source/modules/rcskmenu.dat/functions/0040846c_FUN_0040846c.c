/*
 * FUN_0040846c at 0040846c
 * undefined __register FUN_0040846c(char * param_1, char * param_2, int param_3)
 * Address ranges: 0040846c-004084b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040846c(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined3 uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  bool bVar9;
  
  iVar4 = 0;
  iVar6 = param_3;
  pcVar8 = param_2;
  if (param_3 != 0) {
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    iVar6 = param_3 - iVar6;
    bVar9 = true;
LAB_00408485:
    do {
      if (iVar6 != 0) {
        iVar6 = iVar6 + -1;
        pcVar1 = param_2 + 1;
        pcVar8 = param_1 + 1;
        bVar9 = *param_1 == *param_2;
        param_1 = pcVar8;
        param_2 = pcVar1;
        if (bVar9) goto LAB_00408485;
      }
      if (bVar9) {
        return;
      }
      bVar3 = param_1[-1];
      uVar5 = (undefined3)((uint)iVar4 >> 8);
      iVar4 = CONCAT31(uVar5,bVar3);
      if ((0x60 < bVar3) && (bVar3 < 0x7b)) {
        iVar4 = CONCAT31(uVar5,bVar3 - 0x20);
      }
      bVar3 = param_2[-1];
      uVar7 = (uint)bVar3;
      if ((0x60 < bVar3) && (bVar3 < 0x7b)) {
        uVar7 = (uint)(byte)(bVar3 - 0x20);
      }
      iVar4 = iVar4 - uVar7;
      bVar9 = true;
    } while (iVar4 == 0);
  }
  return;
}


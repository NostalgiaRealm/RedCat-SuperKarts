/*
 * FUN_004084d4 at 004084d4
 * char * __register FUN_004084d4(char * param_1, char * param_2)
 * Address ranges: 004084d4-00408524
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_004084d4(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  
  if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
    uVar2 = 0xffffffff;
    pcVar7 = param_2;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar2 - 1;
    if (uVar3 != 0) {
      uVar4 = 0xffffffff;
      pcVar7 = param_1;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      iVar5 = ~uVar4 - uVar3;
      bVar9 = iVar5 == 0;
      if (uVar3 <= ~uVar4 && !bVar9) {
        do {
          pcVar7 = param_1;
          do {
            param_1 = pcVar7;
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            param_1 = pcVar7 + 1;
            bVar9 = *param_2 == *pcVar7;
            pcVar7 = param_1;
          } while (!bVar9);
          iVar6 = ~uVar2 - 2;
          pcVar8 = param_1;
          pcVar7 = param_2;
          if (!bVar9) {
            return (char *)0x0;
          }
          do {
            if (iVar6 == 0) break;
            bVar9 = pcVar7[1] == *pcVar8;
            iVar6 = iVar6 + -1;
            pcVar8 = pcVar8 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar9);
          if (bVar9) {
            return param_1 + -1;
          }
        } while( true );
      }
    }
  }
  return (char *)0x0;
}


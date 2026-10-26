/*
 * FUN_00409d34 at 00409d34
 * undefined4 __register FUN_00409d34(undefined * param_1)
 * Address ranges: 00409d34-00409d85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00409d34(undefined *param_1)

{
  char *pcVar1;
  byte *pbVar2;
  PCNZCH pCVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = 7;
  piVar4 = &DAT_0047d5bc;
  puVar5 = &DAT_0047d5d8;
  while( true ) {
    if (*piVar4 == 0) {
      return 0;
    }
    pcVar1 = FUN_00403f94(param_1);
    pbVar2 = FUN_00403f94((undefined *)*piVar4);
    pCVar3 = FUN_0040b820(pbVar2,pcVar1);
    if (pCVar3 != (PCNZCH)0x0) break;
    puVar5 = puVar5 + 1;
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return 0;
    }
  }
  return *puVar5;
}


/*
 * FUN_00408174 at 00408174
 * int __register FUN_00408174(undefined * param_1, undefined * param_2)
 * Address ranges: 00408174-004081c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00408174(undefined *param_1,undefined *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_00403dd0((int)param_2);
  pcVar2 = FUN_00403f94(param_1);
  do {
    if (iVar1 < 1) {
      return iVar1;
    }
    if ((param_2[iVar1 + -1] != '\0') &&
       (pcVar3 = FUN_004084b4(pcVar2,param_2[iVar1 + -1]), pcVar3 != (char *)0x0)) {
      uVar4 = FUN_0040b570(param_2,iVar1);
      if ((char)uVar4 != '\x02') {
        return iVar1;
      }
      iVar1 = iVar1 + -1;
    }
    iVar1 = iVar1 + -1;
  } while( true );
}


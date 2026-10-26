/*
 * FUN_004059e0 at 004059e0
 * undefined __register FUN_004059e0(undefined * param_1, char * param_2)
 * Address ranges: 004059e0-00405a0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004059e0(undefined *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = param_2;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00405903(param_1,-(~uVar2 - 1));
  FUN_00405898(param_1,param_2,~uVar2 - 1);
  return;
}


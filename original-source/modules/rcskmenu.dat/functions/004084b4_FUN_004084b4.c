/*
 * FUN_004084b4 at 004084b4
 * char * __register FUN_004084b4(char * param_1, char param_2)
 * Address ranges: 004084b4-004084d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_004084b4(char *param_1,char param_2)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  bool bVar4;
  
  uVar2 = 0xffffffff;
  bVar4 = true;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    bVar4 = *pcVar3 == '\0';
    pcVar3 = pcVar3 + 1;
  } while (!bVar4);
  uVar2 = ~uVar2;
  do {
    pcVar3 = param_1;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar3 = param_1 + 1;
    bVar4 = param_2 == *param_1;
    param_1 = pcVar3;
  } while (!bVar4);
  pcVar1 = (char *)0x0;
  if (bVar4) {
    pcVar1 = pcVar3 + -1;
  }
  return pcVar1;
}


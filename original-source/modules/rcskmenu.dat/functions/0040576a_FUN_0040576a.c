/*
 * FUN_0040576a at 0040576a
 * undefined __register FUN_0040576a(undefined4 * param_1, char * param_2)
 * Address ranges: 0040576a-004057bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040576a(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  
  param_1[5] = param_1 + 0x53;
  *param_1 = 0;
  param_1[1] = 0xd7b0;
  param_1[2] = 0x80;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = FUN_004055dc;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  pcVar3 = (char *)(param_1 + 0x12);
  if (param_2 != (char *)0x0) {
    cVar4 = -0x7e;
    do {
      pcVar2 = pcVar3;
      cVar1 = *param_2;
      *pcVar2 = cVar1;
      if (cVar1 == '\0') {
        return;
      }
      cVar1 = param_2[1];
      param_2 = param_2 + 2;
      pcVar2[1] = cVar1;
      if (cVar1 == '\0') {
        return;
      }
      cVar4 = cVar4 + -1;
      pcVar3 = pcVar2 + 2;
    } while (cVar4 != '\0');
    pcVar3 = pcVar2 + 1;
  }
  *pcVar3 = '\0';
  return;
}


/*
 * FUN_004c7738 at 004c7738
 * undefined FUN_004c7738(void)
 * Address ranges: 004c7738-004c77f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c7738(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  
  if (DAT_006b7dcc == 0) {
    FUN_004c72c4();
  }
  iVar5 = 0;
  for (pcVar6 = DAT_006b6734; *pcVar6 != '\0'; pcVar6 = pcVar6 + sVar2 + 1) {
    if (*pcVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen(pcVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  DAT_006b6710 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_006b6734;
  pcVar6 = DAT_006b6734;
  while (cVar1 != '\0') {
    sVar2 = _strlen(pcVar6);
    if (*pcVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_004c51f0(*puVar3,pcVar6);
      puVar3 = puVar3 + 1;
    }
    pcVar6 = pcVar6 + sVar2 + 1;
    cVar1 = *pcVar6;
  }
  FUN_004bff99(DAT_006b6734);
  DAT_006b6734 = (char *)0x0;
  *puVar3 = 0;
  DAT_006b7dc8 = 1;
  return;
}


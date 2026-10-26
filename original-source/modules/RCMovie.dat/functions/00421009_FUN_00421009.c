/*
 * FUN_00421009 at 00421009
 * undefined __stdcall FUN_00421009(void)
 * Address ranges: 00421009-004210c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00421009(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_0043f928 == 0) {
    FUN_00424bb9();
  }
  iVar5 = 0;
  for (puVar6 = DAT_0043e2b4; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  DAT_0043e2e8 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_0043e2b4;
  puVar6 = DAT_0043e2b4;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_0041f7a0((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_0041fd93(DAT_0043e2b4);
  DAT_0043e2b4 = (uint *)0x0;
  *puVar3 = 0;
  DAT_0043f924 = 1;
  return;
}


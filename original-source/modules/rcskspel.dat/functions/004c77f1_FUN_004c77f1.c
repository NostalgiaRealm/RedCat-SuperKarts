/*
 * FUN_004c77f1 at 004c77f1
 * undefined FUN_004c77f1(void)
 * Address ranges: 004c77f1-004c7889
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c77f1(void)

{
  void *pvVar1;
  char *pcVar2;
  int local_c;
  int local_8;
  
  if (DAT_006b7dcc == 0) {
    FUN_004c72c4();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_006b67cc,0x104);
  _DAT_006b6720 = &DAT_006b67cc;
  pcVar2 = &DAT_006b67cc;
  if (*DAT_006b7dc4 != '\0') {
    pcVar2 = DAT_006b7dc4;
  }
  FUN_004c788a(pcVar2,0,0,&local_8,&local_c);
  pvVar1 = _malloc(local_c + local_8 * 4);
  if (pvVar1 == (void *)0x0) {
    __amsg_exit(8);
  }
  FUN_004c788a(pcVar2,pvVar1,(void *)((int)pvVar1 + local_8 * 4),&local_8,&local_c);
  _DAT_006b6708 = pvVar1;
  _DAT_006b6704 = local_8 + -1;
  return;
}


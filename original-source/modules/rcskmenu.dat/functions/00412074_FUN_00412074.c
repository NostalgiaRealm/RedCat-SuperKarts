/*
 * FUN_00412074 at 00412074
 * undefined __register FUN_00412074(int param_1, char * param_2)
 * Address ranges: 00412074-00412119
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412074(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  char *local_c;
  int local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_c = (char *)0x0;
  puStack_20 = &LAB_0041211a;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  local_8 = 0;
  iVar1 = local_8;
  if (param_2 != (char *)0x0) {
    while (pcVar4 = param_2, iVar1 = param_1, *param_2 != '\0') {
      for (; (*pcVar4 != '\0' && (1 < (byte)(*pcVar4 - 0x2dU))); pcVar4 = pcVar4 + 1) {
      }
      FUN_00403c38((int *)&local_c,(undefined4 *)param_2,(int)pcVar4 - (int)param_2);
      iVar2 = FUN_00414c8c(param_1,local_c);
      if ((iVar2 == 0) && (uVar3 = FUN_00407d58(local_c,"Owner"), (char)uVar3 != '\0')) {
        iVar2 = param_1;
      }
      iVar1 = local_8;
      if (iVar2 == 0) break;
      param_2 = pcVar4;
      if (*pcVar4 == '.') {
        param_2 = pcVar4 + 1;
      }
      if (*param_2 == '-') {
        param_2 = param_2 + 1;
      }
      param_1 = iVar2;
      if (*param_2 == '>') {
        param_2 = param_2 + 1;
      }
    }
  }
  local_8 = iVar1;
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00412121;
  puStack_20 = (undefined1 *)0x412119;
  FUN_00403b50((int *)&local_c);
  return;
}


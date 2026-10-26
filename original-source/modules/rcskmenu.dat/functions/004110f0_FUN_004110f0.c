/*
 * FUN_004110f0 at 004110f0
 * undefined __register FUN_004110f0(int * param_1, char * param_2)
 * Address ranges: 004110f0-00411186
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004110f0(int *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int local_c;
  int *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_c = 0;
  puStack_18 = &LAB_004111a4;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_20 = (undefined1 *)0x411117;
  local_8 = param_1;
  FUN_0041073c(param_1);
  puStack_24 = &LAB_00411187;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  (**(code **)(*local_8 + 0x40))();
  if (param_2 != (char *)0x0) {
    while (pcVar2 = param_2, *param_2 != '\0') {
      for (; ((cVar1 = *pcVar2, cVar1 != '\0' && (cVar1 != '\n')) && (cVar1 != '\r'));
          pcVar2 = pcVar2 + 1) {
      }
      FUN_00403c38(&local_c,(undefined4 *)param_2,(int)pcVar2 - (int)param_2);
      (**(code **)(*local_8 + 0x34))(local_8,local_c);
      param_2 = pcVar2;
      if (*pcVar2 == '\r') {
        param_2 = pcVar2 + 1;
      }
      if (*param_2 == '\n') {
        param_2 = param_2 + 1;
      }
    }
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_0041118e;
  puStack_24 = (undefined1 *)0x411186;
  FUN_004107f8(local_8);
  return;
}


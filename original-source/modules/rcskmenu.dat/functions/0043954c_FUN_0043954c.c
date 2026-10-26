/*
 * FUN_0043954c at 0043954c
 * char __register FUN_0043954c(int * param_1, int param_2, undefined4 param_3, int param_4)
 * Address ranges: 0043954c-00439670;0043968f-0043969c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_0043954c(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_24;
  undefined1 *puStackY_20;
  int local_c;
  char local_5;
  
  local_5 = '\x01';
  local_c = *(int *)(*param_1 + 0x58);
  if (local_c != 0) {
    puStackY_20 = (undefined1 *)0x43957a;
    local_5 = FUN_0043954c(&local_c,param_2 + 1,param_3,param_4);
  }
  if ((local_5 != '\0') && (local_5 != '\x03')) {
    if (local_5 == '\x02') {
      if ((*(int *)(param_4 + -4) == 0) ||
         (*(short *)(*(int *)(param_4 + -4) + 0x54) != *(short *)(param_4 + -6))) {
        uVar1 = FUN_004393f8(*(int *)(param_4 + -0xc));
        *(undefined4 *)(param_4 + -4) = uVar1;
        if (*(int *)(param_4 + -4) == 0) {
          return '\x03';
        }
      }
      iVar2 = thunk_FUN_00439542(*(int *)(param_4 + -4),param_2);
      *param_1 = iVar2;
      if (*param_1 == 0) {
        return local_5;
      }
      if (*(int *)(*param_1 + 0x58) != local_c) {
        return local_5;
      }
      if (param_2 == 0) {
        local_5 = '\x01';
      }
    }
    if (*(char *)(*param_1 + 0x2d) == '\0') {
      local_5 = '\0';
    }
    else {
      puStackY_20 = &LAB_00439671;
      uStackY_24 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStackY_24;
      if ((*(byte *)(*(int *)(param_4 + -0xc) + 0x20) & 0x10) == 0) {
        FUN_0043855c(*param_1);
      }
      (**(code **)(*(int *)*param_1 + 0x40))();
      if ((*(int *)(param_4 + -4) == 0) ||
         ((*param_1 != *(int *)(param_4 + -4) &&
          (*(short *)(*(int *)(param_4 + -4) + 0x54) != *(short *)(param_4 + -6))))) {
        local_5 = '\x02';
      }
      *in_FS_OFFSET = uStackY_24;
    }
  }
  return local_5;
}


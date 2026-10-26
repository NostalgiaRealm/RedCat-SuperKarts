/*
 * FUN_00439070 at 00439070
 * undefined1 __register FUN_00439070(int param_1, char param_2)
 * Address ranges: 00439070-004391aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00439070(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_18;
  int local_14;
  
  local_18 = 0;
  if ((param_2 != '\0') ||
     (((*(byte *)(param_1 + 0x20) & 0x10) == 0 && (cVar1 = FUN_004391e8(param_1), cVar1 != '\0'))))
  {
    local_14 = 0;
    iVar5 = 0;
    iVar4 = 0;
    iVar2 = FUN_00438084(param_1);
    iVar3 = local_14;
    if (-1 < iVar2 + -1) {
      do {
        iVar3 = FUN_00438094(param_1,iVar4);
        if (*(char *)(iVar3 + 0x32) != '\0') {
          iVar3 = FUN_00438094(param_1,iVar4);
          cVar1 = FUN_0043904c(iVar3);
          iVar3 = iVar4;
          if (cVar1 == '\0') break;
          iVar3 = FUN_00438094(param_1,iVar4);
          *(undefined1 *)(iVar3 + 0x32) = 0;
          local_18 = 1;
        }
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + -1;
        iVar3 = local_14;
      } while (iVar2 != 0);
    }
    local_14 = iVar3;
    iVar4 = FUN_00438084(param_1);
    if (local_14 <= iVar4 + -1) {
      iVar3 = ((iVar4 + -1) - local_14) + 1;
      iVar4 = local_14;
      do {
        iVar2 = FUN_00438094(param_1,iVar4);
        cVar1 = FUN_0043904c(iVar2);
        if (cVar1 == '\0') {
          iVar2 = FUN_00438094(param_1,iVar4);
          if (*(char *)(iVar2 + 0x32) != '\0') {
            if (iVar5 != 0) {
              *(undefined1 *)(iVar5 + 0x32) = 1;
              local_18 = 1;
            }
            iVar5 = 0;
            local_14 = iVar4;
          }
        }
        else {
          if (iVar5 != 0) {
            *(undefined1 *)(iVar5 + 0x32) = 0;
            local_18 = 1;
          }
          iVar5 = FUN_00438094(param_1,iVar4);
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    iVar4 = FUN_00438084(param_1);
    iVar4 = iVar4 + -1;
    if (local_14 - iVar4 == 0 || local_14 < iVar4) {
      iVar3 = (local_14 - iVar4) + -1;
      do {
        iVar2 = FUN_00438094(param_1,iVar4);
        if (*(char *)(iVar2 + 0x32) != '\0') {
          iVar2 = FUN_00438094(param_1,iVar4);
          cVar1 = FUN_0043904c(iVar2);
          if (cVar1 == '\0') {
            return local_18;
          }
          iVar2 = FUN_00438094(param_1,iVar4);
          *(undefined1 *)(iVar2 + 0x32) = 0;
          local_18 = 1;
        }
        iVar4 = iVar4 + -1;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0);
    }
  }
  return local_18;
}


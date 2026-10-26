/*
 * FUN_00403d08 at 00403d08
 * undefined __register FUN_00403d08(int * param_1, char * param_2)
 * Address ranges: 00403d08-00403d33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403d08(int *param_1,char *param_2)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = 0;
  pcVar2 = param_2;
  if (param_2 != (char *)0x0) {
    for (; *pcVar2 != '\0'; pcVar2 = pcVar2 + 4) {
      if (pcVar2[1] == '\0') {
LAB_00403d29:
        pcVar2 = pcVar2 + 1;
        break;
      }
      if (pcVar2[2] == '\0') {
LAB_00403d28:
        pcVar2 = pcVar2 + 1;
        goto LAB_00403d29;
      }
      if (pcVar2[3] == '\0') {
        pcVar2 = pcVar2 + 1;
        goto LAB_00403d28;
      }
    }
    uVar1 = (int)pcVar2 - (int)param_2;
  }
  FUN_00403c38(param_1,(undefined4 *)param_2,uVar1);
  return;
}


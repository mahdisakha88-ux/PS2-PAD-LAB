#include <tamtypes.h>
#include <kernel.h>
#include <libpad.h>
#include <debug.h>

static u8 padBuf[256] __attribute__((aligned(64)));

int main(void)
{
    struct padButtonStatus buttons;

    init_scr();
    padInit(0);

    scr_printf("================================\n");
    scr_printf("       PS2 PAD LAB\n");
    scr_printf("   DualShock 2 Controller Test\n");
    scr_printf("================================\n");

    if (padPortOpen(0, 0, padBuf) == 0) {
        scr_printf("Controller not detected!\n");
        SleepThread();
    }

    while (1) {
        int state = padGetState(0, 0);

        if (state == PAD_STATE_STABLE) {
            if (padRead(0, 0, &buttons)) {
                scr_printf("\nController connected!\n");
                scr_printf("Buttons: %04X\n", buttons.btns);
                scr_printf("Left X: %d\n", buttons.ljoy_h);
                scr_printf("Left Y: %d\n", buttons.ljoy_v);
                scr_printf("Right X: %d\n", buttons.rjoy_h);
                scr_printf("Right Y: %d\n", buttons.rjoy_v);
            }
        }

        DelayThread(10000);
    }

    return 0;
}

#include <cmath>
#include <numbers>
 
#include <CDLib.h>


int main()
{
    constexpr float PI = std::numbers::pi;
    constexpr float kFPS = 60.f;

    constexpr uint32_t kWidth = 800;
    constexpr uint32_t kHeight = 600;
    createWindow(kWidth, kHeight, "CDLib demo");

    while (true)
    {
        float t = getTime();

        sf::Color bg(
            static_cast<uint8_t>(20 + 10 * std::sin(t)),
            static_cast<uint8_t>(20 + 10 * std::sin(t + 2.f)),
            static_cast<uint8_t>(40 + 10 * std::sin(t + 4.f))
        );

        setFillColor(bg);
        clear();

        {
            setFillColor(sf::Color::White);
            setColor(sf::Color::White);
            setThinkness(2.f);
            drawCircle(kWidth / 2, kHeight / 2, 250);
        }

        {
            float angle = 2.f * PI * t / 10.f;
            int cx = kWidth / 2, cy = kHeight / 2;
            int ex = cx + static_cast<int>(200.f * std::cos(angle));
            int ey = cy + static_cast<int>(200.f * std::sin(angle));

            setColor(sf::Color::Black);
            setThinkness(10.f);
            drawLine(cx, cy, ex, ey);
        }

        display();
        sleep(1.f / kFPS);
    }

    return 0;
}

// https://www.cnblogs.com/ailumiyana/p/10016965.html
#ifndef _thread_pool_HPP
#define _thread_pool_HPP

#include <vector>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

#ifdef __SOLA_LOGGING_ENABLED
#define __SOLA_LOG(level, msg) sola::level(msg, __FILE__, __LINE__);
#else
#define __SOLA_LOG(level, msg)
#endif

namespace sola
{
    class logger_iface
    {
    public:
        logger_iface(void) = default;
        virtual ~logger_iface(void) = default;
        logger_iface(const logger_iface&) = default;
        logger_iface& operator=(const logger_iface&) = default;

        virtual void debug(const std::string& msg, const std::string& file, std::size_t line) = 0;
        virtual void info(const std::string& msg, const std::string& file, std::size_t line) = 0;
        virtual void warn(const std::string& msg, const std::string& file, std::size_t line) = 0;
        virtual void error(const std::string& msg, const std::string& file, std::size_t line) = 0;
    };

    class logger: public logger_iface
    {
    public:
        enum class log_level
        {
            error = 0,
            warn = 1,
            info = 2,
            debug = 3
        };

        logger(log_level level=log_level::info);
        ~logger(void) = default;
        logger(const logger&) = default;
        logger& operator=(const logger&) = default;

        void debug(const std::string& msg, const std::string& file, std::size_t line);
        void info(const std::string& msg, const std::string& file, std::size_t line);
        void warn(const std::string& msg, const std::string& file, std::size_t line);
        void error(const std::string& msg, const std::string& file, std::size_t line);
    
    private:
        log_level m_level;
        std::mutex m_mutex;
    };

    extern std::unique_ptr<logger_iface> active_logger;

    void debug(const std::string& msg, const std::string& file, std::size_t line);
    void info(const std::string& msg, const std::string& file, std::size_t line);
    void warn(const std::string& msg, const std::string& file, std::size_t line);
    void error(const std::string& msg, const std::string& file, std::size_t line);

    class thread_pool 
    {
    public:
        typedef std::function<void()> task_t;
        
        thread_pool(int init_size=3);
        ~thread_pool();

        void stop();
        void add_task(const task_t&);

    private:
        thread_pool(const thread_pool&); // 禁止拷贝复制
        const thread_pool& operator=(const thread_pool&);

        bool is_started()
        {
            return m_is_started;
        }

        void start();

        void thread_loop();
        task_t take();

        typedef std::vector<std::thread*> threads_t;
        typedef std::deque<task_t> tasks_t;

        int m_init_threads_size;

        threads_t m_threads;
        tasks_t m_tasks;

        std::mutex m_mutex;
        std::condition_variable m_cond;
        bool m_is_started;
    };
}
#endif